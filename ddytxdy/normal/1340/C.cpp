    #include<bits/stdc++.h>
    #define LL long long
    #define pb push_back
    using namespace std;
    const int N=1e4+50;
    int n,m,a[N],g,r,ans;bool f[N][N];
    vector<int>v[N];
    int main(){
        scanf("%d%d",&n,&m);
        for(int i=1;i<=m;i++)scanf("%d",&a[i]);
        sort(a+1,a+m+1);
        scanf("%d%d",&g,&r);f[1][g]=1;v[0].pb(1);
        while(1){
            for(int i=0;i<g;i++){
                for(int j=0;j<v[i].size();j++){
                    int x=v[i][j],tt;if(x==m)printf("%d\n",ans+i),exit(0);
                    if(x>1&&(tt=i+a[x]-a[x-1])<=g&&!f[x-1][tt])f[x-1][tt]=1,v[tt].pb(x-1);
                    if(x<m&&(tt=i+a[x+1]-a[x])<=g&&!f[x+1][tt])f[x+1][tt]=1,v[tt].pb(x+1);//cout<<1;
                }
                v[i].clear();
            }
            if(!v[g].size())puts("-1"),exit(0);
            for(int i=0;i<v[g].size();i++){
                if(v[g][i]==m)printf("%d\n",ans+g),exit(0);
                v[0].pb(v[g][i]);
            }
            v[g].clear();ans+=g+r;
        }
        return 0;
    }