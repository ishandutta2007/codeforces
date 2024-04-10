#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
lli am[(int)1e7+1];
lli stffleft[(int)1e7+1];
bool prime[(int)1e7+1];
map<int,lli> pf;
vector<int> stff;
lli maxval=1e7;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int k;
    cin>>k;
    lli a;
    for(int i=0;i<k;i++){
        cin>>a;
        stff.push_back(a);
    }
    int szstff=sz(stff);
    sort(stff.begin(),stff.end());
    lli ind=szstff;
    for(int i=2;i<=maxval;i++){
        while (ind && i > stff[szstff - ind])ind--;
        stffleft[i]=ind;
    }
    for(int i=2;i<=maxval;i++){
        if(!prime[i]){
            lli nums=1;
            lli cur=i;
            while(cur<=maxval){
                for(int j=cur;j<=maxval;j+=cur){
                    am[j]=nums;
                }
                cur*=i;
                nums++;
            }
            lli tot=0;
            for (int j = i; j <= maxval; j += i) {
                prime[j] = true;
                tot += stffleft[j] * am[j];
            }
            if(tot)pf[i]+=tot;
        }
    }
    lli ma=1;
    for(auto x:pf){
        lli lo=1,hi=x.second;
        while(lo!=hi){
            lli mid=(lo+hi)/2;
            lli te=0;
            lli cur=x.first;
            lli act=mid*x.first;
            while(cur<=act){
                te+=act/cur;
                cur=cur*x.first;
            }
            if(te>=x.second)hi=mid;
            else lo=mid+1;
        }
        ma=max(ma,x.first*lo);
    }
    printf("%lli\n",ma);
    return 0;
}