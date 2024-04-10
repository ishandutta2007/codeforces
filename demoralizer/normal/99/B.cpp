#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define M 1000000007
#define fr first
#define sc second
#define vc vector
#define r0 return 0
int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    map<int,int> m,m2;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int t;cin>>t;
        m[t]++;
        m2[t]=i+1;
    }
    map<int,int>::iterator i=m.begin();
    int a,b,c;
    switch(m.size()){
        case 1:cout<<"Exemplary pages.";r0;
        case 3:
            a=i->sc;i++;b=i->sc;i++;c=i->sc;
            if(a==1&&c==1){
                i=m.begin();
                a=i->fr;
                i++;
                b=i->fr;
                i++;
                c=i->fr;
                if(a+c==2*b){
                    cout<<(c-b)<<" ml. from cup #"<<(m2[a])<<" to cup #"<<(m2[c])<<".";
                    r0;
                }
            }
        case 2:
            if(n==2){
                a=i->fr;i++;b=i->fr;
                if((b-a)%2==0){
                    cout<<(b-a)/2<<" ml. from cup #"<<(m2[a])<<" to cup #"<<(m2[b])<<".";
                    r0;
                }
            }
        default:cout<<"Unrecoverable configuration.";r0;
    }
}