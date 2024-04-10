#include<bits/stdc++.h>
using namespace std;

int n,k,V,a[5005];
bool f[5005][5005],imp[5005];
vector<pair<pair<int,int>,int>> ans;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    if(fopen("vento.in","r")){
        freopen("vento.in","r",stdin);
        freopen("vento.out","w",stdout);
    }

    cin>>n>>k>>V;
    int sum=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    if(sum<V){
        cout<<"NO\n";
        return 0;
    }
    f[0][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<k;j++)if(f[i-1][j]){
            f[i][j]=1;
            f[i][(j+a[i])%k]=1;
        }
    }
    if(f[n][V%k]){
        cout<<"YES\n";
    }else{
        cout<<"NO\n";
        return 0;
    }
    {
        int x=n,y=V%k,py;
        while(x){
            if(f[x-1][py=(y-a[x]%k+k)%k]){
                imp[x]=1;
                y=py;
            }
            x--;
        }
    }
    int fin=1;
    while(fin<=n&&!imp[fin])fin++;
    if(fin>n){
        for(int i=2;i<=n;i++)if(a[i]){
            ans.emplace_back(make_pair(i,1),(a[i]+k-1)/k);
            a[1]+=a[i];
            a[i]=0;
        }
        if(V)ans.emplace_back(make_pair(1,2),V/k);
    }else{
        for(int i=1;i<=n;i++)if(i!=fin&&imp[i]&&a[i]){
            ans.emplace_back(make_pair(i,fin),(a[i]+k-1)/k);
            a[fin]+=a[i];
            a[i]=0;
        }
        if(a[fin]>V){
            int trash=fin==1?2:1;
            ans.emplace_back(make_pair(fin,trash),(a[fin]-V)/k);
            a[trash]+=a[fin]-V;
            a[fin]=V;
        }
        if(a[fin]<V){
            int sink=1;
            while(imp[sink])sink++;
            for(int i=1;i<=n;i++)if(i!=sink&&!imp[i]){
                ans.emplace_back(make_pair(i,sink),(a[i]+k-1)/k);
                a[sink]+=a[i];
                a[i]=0;
            }
            ans.emplace_back(make_pair(sink,fin),(V-a[fin])/k);
            a[sink]-=V-a[fin];
            a[fin]=V;
        }
    }
    for(auto &p:ans){
        cout<<p.second<<' '<<p.first.first<<' '<<p.first.second<<'\n';
    }

    return 0;
}