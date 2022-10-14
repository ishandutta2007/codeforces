#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=2e6+1;
set<int> canuse;
void insert(int a){
    for(int i=2;i*i<=a;i++){
        int cnt=0;
        while(a%i==0){
            a/=i;
            cnt++;
        }
        if(cnt){
            if(canuse.count(i)){
                for(int j=i;j<MAXN;j+=i){
                    canuse.erase(j);
                }
            }
        }
    }
    if(a!=1){
        if(canuse.count(a)){
            for(int j=a;j<MAXN;j+=a){
                canuse.erase(j);
            }
        }
    }
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    for(int i=2;i<=2e6;i++)canuse.insert(i);
    int n;
    cin>>n;
    int a;
    bool equal=true;
    for(int i=0;i<n;i++){
        cin>>a;
        if(equal){
            if(canuse.count(a)) {
                insert(a);
                printf("%d ", a);
            }
            else{
                int k=*canuse.lower_bound(a);
                insert(k);
                printf("%d ", k);
                equal=false;
            }
        }
        else{
            int k=*canuse.begin();
            insert(k);
            printf("%d ", k);
        }
    }
    return 0;
}