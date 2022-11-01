#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int V=2e7;

int n,c[V+5],m[V+5];
ll f[V+5];
bool pd[V+5];
vector<int> prime;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for(int i=2;i<=V;i++){
        if(!pd[i])prime.emplace_back(i);
        for(int x:prime){
            if(V/x<i)break;
            pd[i*x]=1;
            if(i%x==0)break;
        }
    }
    cin>>n;
    for(int i=1,a;i<=n;i++){
        cin>>a;
        c[a]++;
    }
    for(int i=V;i>=1;i--){
        int i2=i*2;
        m[i]=i2<=V?m[i2]+c[i]:c[i];
        for(int j=i*3;j<=V;j+=i2)m[i]+=c[j];
    }
    for(int i=V;i>=1;i--)if(m[i]){
        f[i]=(ll)i*m[i];
        for(int x:prime){
            if(V/x<i)break;
            f[i]=max(f[i],f[x*i]+(ll)i*(m[i]-m[x*i]));
        }
    }
    cout<<*max_element(f+1,f+V+1);

    return 0;
}