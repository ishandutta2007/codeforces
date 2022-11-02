#include <bits/stdc++.h>
using namespace std;
constexpr int CT=200008;
//vector<int> primes;
vector<int> scope[CT];
vector<int> counts[CT];
bool is_prime[CT];
void mult(long long& ans, int val, int t){
    while(t-->0){
        ans*=val;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    fill(is_prime+2, is_prime+CT, true);
    for(int i=2;i<CT;++i){
        if(is_prime[i]){
            //primes.push_back(i);
            scope[i].push_back(i);
            for(int j=i*2;j<CT;j+=i){
                is_prime[j]=false;
                scope[j].push_back(i);
            }
        }
    }
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        int num;
        cin>>num;
        int cl=num;
        for(int x:scope[num]){
            int ct=1;
            cl/=x;
            while(cl%x==0){
                ++ct;
                cl/=x;
            }
            counts[x].push_back(ct);
        }
    }
    long long ans=1;
    for(int i=2;i<CT;++i){
        if(is_prime[i]){
            if(counts[i].size()+1<n)continue;
            sort(counts[i].begin(),counts[i].end());
            if(counts[i].size()==n)mult(ans,i,counts[i][1]);
            else mult(ans,i,counts[i][0]);
        }
    }
    cout<<ans<<'\n';
}