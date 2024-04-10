#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>
#include <cstdio>
#include <cctype>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <complex>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cwchar>
#include <cwctype>
#include <exception>
#include <locale>
#include <numeric>
#include <new>
#include <stdexcept>
#include <limits>
#include <valarray>
#include <set>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <list>
#include <utility>
#include <bitset>
#include <algorithm>
#include <functional>
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define MP make_pair
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF=1e9+7;
struct cindylist{
	int data;
	cindylist *prev,*next;
	cindylist *n317;
	cindylist(int d=0){
		data=d;
		prev=next=n317=NULL;
	}
	cindylist(const cindylist &oth){
		data=oth.data;
		prev=oth.prev;
		next=oth.next;
		n317=oth.n317;
	}
};
int cnt[317][100005];
cindylist* ptr[317];
vector<int> H;
cindylist* head;
void CL_init(){
	head=new cindylist;
}
cindylist* CL_kth(int k){
	if(k<0)return head;
	cindylist* cur=head->next;
	while(k>=317&&cur!=NULL){
		cur=cur->n317;
		k-=317;
	}
	while(k>0&&cur!=NULL){
		cur=cur->next;
		k--;
	}
	return cur;
}
int CL_count(int k,int v){
	int ans=0,cc=0;
	cindylist* cur=head->next;
	while(k>=317){
		ans+=cnt[cc][v];
		cc++;
		cur=cur->n317;
		k-=317;
	}
	while(k>0){
		if(cur->data==v)ans++;
		cur=cur->next;
		k--;
	} 
	return ans;
}
cindylist* CL_insert(cindylist *replc,cindylist *cont){
	cont->next=replc->next;
	cont->prev=replc;
	if(replc->next!=NULL)replc->next->prev=cont;
	replc->next=cont;
	cont->n317=replc->n317;
	cindylist *cur=cont,*c2=cont;
	rep(k,317){
		if(cur->prev!=NULL)cur=cur->prev;
		else if(c2!=NULL)c2=c2->next;
	}
	while(cur!=cont){
		cur->n317=c2;
		cur=cur->next;
		if(c2!=NULL)c2=c2->next;
	}
	cur=cont;
	rep(k,317){
		cur=cur->next;
		if(cur==NULL)break;
	}
	return cont;
}
void CL_erase(cindylist *replc){
	replc->prev->next=replc->next;
	if(replc->next!=NULL)replc->next->prev=replc->prev;
	cindylist *cur=replc->prev,*c2=cur->next,*c3=cur->next;
	rep(k,316){
		if(cur->prev!=NULL)cur=cur->prev;
		else if(c2!=NULL)c2=c2->next;
	}
	while(cur!=c3){
		cur->n317=c2;
		cur=cur->next;
		if(c2!=NULL)c2=c2->next;
	}
}
int main(){
	CL_init();
	cindylist *rear=head;
	int n,q,x,ans=0;
	scanf("%d",&n);
	rep(k,n){
		scanf("%d",&x);
		rear=CL_insert(rear,new cindylist(x));
	}
	cindylist* cur=head->next;
	q=0;
	while(cur!=NULL){
		cindylist* c2=cur;
		rep(k,317){
			cnt[q][c2->data]++;
			c2=c2->next;
			if(c2==NULL)break;
		}
		ptr[q++]=cur;
		cur=cur->n317;
	}
	scanf("%d",&q);
	for(int i=0;i<q;i++){
		int t,v,l,r;
		scanf("%d%d%d",&t,&l,&r);
		l=(l+ans-1)%n;
		r=(r+ans-1)%n;
		if(l>r)swap(l,r);
		if(t==1){
			cindylist *mov=CL_kth(r),*cur;
			int E=r/317;
			if(r%317){
				cur=ptr[E];
				cnt[E][mov->data]--;
				cur=cur->n317;
				if(cur!=NULL)cnt[E][cur->data]++;
			}else{
				cur=mov;
				E--;
			}
			for(;cur!=NULL;cur=cur->n317){
				E++;
				ptr[E]=cur->next;
				cnt[E][cur->data]--;
				if(cur->n317!=NULL)cnt[E][cur->n317->data]++;
			}
			CL_erase(mov);
			
			mov=new cindylist(mov->data);
			CL_insert(CL_kth(l-1),mov);
			E=l/317;
			if(l%317){
				cur=ptr[E];
				cnt[E][mov->data]++;
				cur=cur->n317;
				if(cur!=NULL)cnt[E][cur->data]--;
			}else{
				cur=mov;
				E--;
			}
			for(;cur!=NULL;cur=cur->n317){
				E++;
				ptr[E]=cur;
				cnt[E][cur->data]++;
				if(cur->n317!=NULL)cnt[E][cur->n317->data]--;
			}
		}else{
			scanf("%d",&v);
			v=(v+ans-1)%n+1;
			ans=CL_count(r+1,v)-CL_count(l,v);
			printf("%d\n",ans);
		}
	}
	return 0;
}