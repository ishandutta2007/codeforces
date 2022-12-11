#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
const int N=3e5+50,inf=1e9;
int n,k,a[N],b[N],val[N],mx;LL ans;
map<int,int>s;
map<int,int>::iterator it,jt;
vector<pii>v[N];
void split(int x){//x-1x
	if(s.count(x))return;
	it=--s.upper_bound(x);
	s[x]=it->se;
}
bool check(int x){
    LL sum=0,now=0,ans1=0,ans2=0;
    memset(val,0,sizeof(val));
    for(int i=1,p=0;i<=n;i++){
        for(int j=0;j<v[i].size();j++)
            if(v[i][j].se<=p){
                now+=v[i][j].fi;
                sum+=1ll*v[i][j].fi*(p-v[i][j].se+1);
            }
            else val[v[i][j].se]+=v[i][j].fi;
        while(now+val[p+1]>=x)sum+=(now+=val[++p]);
        ans1+=p;ans2+=sum;
    }
    if(ans1<k)return 0;
    ans=ans2-x*(ans1-k);return 1;
}
int main(){
    scanf("%d%d",&n,&k);s[1]=0;
    for(int i=1,l,r;i<=n;i++){
        scanf("%d%d",&l,&r);r--;
        split(l);split(r+1);mx=max(mx,r);
        for(it=s.lower_bound(l);it->fi<=r;)
			jt=it++,v[i].pb(mp(it->fi-jt->fi,jt->se+1)),s.erase(jt);
        s[l]=i;v[i].pb(mp(-(r-l+1),i+1));
    }
    for(int i=29,now=0;~i;i--)
        if(check(now|1<<i))now|=1<<i;
    cout<<ans;
}