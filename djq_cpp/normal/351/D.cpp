#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define MP make_pair
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF=1e9+7;
const int BUCKET=317;
int a[100005];
int ql[100005],qr[100005];
vector<int> qy[320][320];
deque<int> app[100005];
unordered_map<int,int> dd[100005];
int cnt[100005];
int can,tot;
void add(unordered_map<int,int>& m,int id){
	m[id]++;
}
void del(unordered_map<int,int>& m,int id){
	if((--m[id])==0)m.erase(m.find(id));
}
inline void insert_left(int pos){
	if(cnt[a[pos]]==0){
		tot++;can++;
	}
	cnt[a[pos]]++;
	if(dd[a[pos]].size()<=1)can--;
	if(!app[a[pos]].empty())add(dd[a[pos]],app[a[pos]].front()-pos);
	app[a[pos]].push_front(pos);
	if(dd[a[pos]].size()<=1)can++;
}
inline void erase_left(int pos){
	if(dd[a[pos]].size()<=1)can--;
	int lf=app[a[pos]].front();app[a[pos]].pop_front();
	if(!app[a[pos]].empty())del(dd[a[pos]],app[a[pos]].front()-lf);
	if(dd[a[pos]].size()<=1)can++;
	cnt[a[pos]]--;
	if(cnt[a[pos]]==0){
		tot--;can--;
	}
}
inline void insert_right(int pos){
	if(cnt[a[pos]]==0){
		tot++;can++;
	}
	cnt[a[pos]]++;
	if(dd[a[pos]].size()<=1)can--;
	if(!app[a[pos]].empty())add(dd[a[pos]],pos-app[a[pos]].back());
	app[a[pos]].push_back(pos);
	if(dd[a[pos]].size()<=1)can++;
}
inline void erase_right(int pos){
	if(dd[a[pos]].size()<=1)can--;
	int lf=app[a[pos]].back();app[a[pos]].pop_back();
	if(!app[a[pos]].empty())del(dd[a[pos]],lf-app[a[pos]].back());
	if(dd[a[pos]].size()<=1)can++;
	cnt[a[pos]]--;
	if(cnt[a[pos]]==0){
		tot--;can--;
	}
}
int ans[100005];
int main(){
	int n,q;
	scanf("%d",&n);
	rep(k,n)scanf("%d",&a[k]);
	scanf("%d",&q);
	rep(k,q){
		scanf("%d%d",&ql[k],&qr[k]);ql[k]--;qr[k]--;
		qy[ql[k]/BUCKET][qr[k]/BUCKET].push_back(k);
	}
	int cl=0,cr=-1;
	rep(i,BUCKET)rep(j,BUCKET)rep(k,qy[i][j].size()){
		int id=qy[i][j][k];
		int l=ql[id],r=qr[id];
		while(cr<r){
			cr++;insert_right(cr);
		}
		while(cl<l){
			erase_left(cl);cl++;
		}
		while(cl>l){
			cl--;insert_left(cl);
		}
		while(cr>r){
			erase_right(cr);cr--;
		}
		ans[id]=tot+(can==0);
	}
	rep(k,q)printf("%d\n",ans[k]);
	return 0;
}