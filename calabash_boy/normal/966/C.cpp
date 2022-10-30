#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn= 1e5+100;
int nxt[maxn*60][2],tot;
int cnt[maxn*60];
int flag[maxn*60];
int n;
LL b[maxn];
LL a[maxn];
LL bas[100];
void insert(LL val){
    int now=0;
    for (int i=61;i>=0;i--){
        LL bit = (val&bas[i]);
        if (bit)bit=1;
        cnt[now]++;
        if (!nxt[now][bit])nxt[now][bit] = ++tot;
        now = nxt[now][bit];
    }
cnt[now]++;
}
LL query(LL Val,int dep,int now,bool same,LL ans){
	//printf("%lld %d %d %d %lld\n",Val,dep,now,same,ans);
	if (dep==-1&&!same)return ans;
	else if (dep==-1&&same)return -1;
//	cnt[now]--;
	LL bit = Val&bas[dep];
	if (bit)bit=1;
	if (!same){
		if (nxt[now][bit]&&cnt[nxt[now][bit]]){
			LL temp = query(Val,dep-1,nxt[now][bit],same,ans);
			if (temp!=-1)return temp;
		}
		if (nxt[now][!bit]&&cnt[nxt[now][!bit]])return query(Val,dep-1,nxt[now][!bit],same,ans+bas[dep]);
		else return -1;
	}else{
		if (bit){
			if (nxt[now][!bit]&&cnt[nxt[now][!bit]]){
				LL temp = query(Val,dep-1,nxt[now][!bit],same,ans+bas[dep]);
				if (temp!=-1)return temp;
				else return -1;
			}else{
				return -1;
			}
		}else{
			//printf("%lld HERE\n",bit);
			if (nxt[now][bit]&&cnt[nxt[now][bit]]){
				LL temp = query(Val,dep-1,nxt[now][bit],same,ans);
				if (temp!=-1)return temp;
			}
			if (nxt[now][!bit]&&cnt[nxt[now][!bit]]) return query(Val,dep-1,nxt[now][!bit],false,ans+bas[dep]);
			//printf("HERE\n");
			return -1;
		}
	}
}
void modify(LL Val){
	int now =0;
	for (int i=61;i>=0;i--){
		cnt[now]--;
		LL bit = Val&bas[i];
		if (bit)bit=1;
		now = nxt[now][bit];
	}
	cnt[now]--;
}
int main(){
    bas[0]=1;
    for (int i=1;i<=63;i++){
        bas[i]=bas[i-1]<<1;
    }
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        scanf("%lld",b+i);
        insert(b[i]);
    }
    for (int i=1;i<=n;i++){
        LL temp = query(a[i-1],61,0,true,0);
	//printf("%lld\n",temp);
        if (temp==-1){
            printf("No\n");
            return 0;
        }else{
		a[i]=temp;
		modify(a[i]^a[i-1]);
	}
    }
    printf("Yes\n");
    for (int i=1;i<=n;i++){
	    printf("%lld ",a[i]^a[i-1]);
    }
    return 0;
}