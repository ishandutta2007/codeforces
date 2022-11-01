#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int V=5e6;

int n,c[V+5],m[V+5];
ll f[V+5];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=1,a;i<=n;i++){
        cin>>a;
        c[a]++;
    }
    for(int i=1;i<=V;i++)for(int j=i;j<=V;j+=i)m[i]+=c[j];
    for(int i=V,cm;i>=1;i--)if(m[i]){
        cm=m[i];
        ll cf=(ll)i*cm;
        for(int j=i*2;j<=V;j+=i)cf=max(cf,f[j]+(ll)i*(cm-m[j]));
        f[i]=cf;
    }
    cout<<*max_element(f+1,f+V+1);

    return 0;
}