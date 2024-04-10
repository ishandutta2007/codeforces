#include<bits/stdc++.h>
using namespace std;
int n,bj[4000010],cnt_l[2000010],cnt_r[2000010];
const int mod=51123987;
void add(int *a,int l,int r){
    a[l]++;
    a[r+1]--;
}
char s[4000010];
int main(){
    scanf("%d",&n);
    s[0]='!';
    s[1]='#';
    for(int i=1;i<=n;i++){
        scanf(" %c",&s[2*i]);
        s[2*i+1]='#';
    }
    int pos=0,mx=0;
	for(int i=1;i<=(n<<1)+1;i++){
		if(i<mx) bj[i]=min(bj[pos*2-i],mx-i);
		else bj[i]=1;
		while(s[i+bj[i]]==s[i-bj[i]]) bj[i]++;
		if(mx<i+bj[i]) mx=i+bj[i],pos=i;
	}
    for(int i=1;i<=(n<<1)+1;i++){
        if(i%2==0){
            int x=i/2;
            bj[i]/=2;
            bj[i]--;
            add(cnt_l,x-bj[i],x);
            add(cnt_r,x,x+bj[i]);
        }
        else{
            int x=i/2;
            bj[i]/=2;
            add(cnt_l,x-bj[i]+1,x);
            add(cnt_r,x+1,x+bj[i]);
        }
    }
    long long ans=0;
    for(int i=1;i<=n;i++){
        cnt_l[i]+=cnt_l[i-1];
        if(cnt_l[i]>=mod) cnt_l[i]-=mod;
        ans+=cnt_l[i];
        if(ans>=mod) ans-=mod;
    }
    for(int i=1;i<=n;i++){
        cnt_r[i]+=cnt_r[i-1];
        if(cnt_r[i]>=mod) cnt_r[i]-=mod;
    }
    long long qian=0;
    ans=ans*(ans-1)/2%mod;
    for(int i=1;i<=n;i++){
        ans-=cnt_l[i]*qian%mod;
        if(ans<0) ans+=mod;
        qian+=cnt_r[i];
        if(qian>=mod) qian-=mod;
    }
    printf("%lld",ans);
}