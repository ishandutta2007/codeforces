#include <bits/stdc++.h>
using namespace std;

long long a,b;
unsigned long long op1,op2;
long long c,m,aa,bb;
unsigned long long ans1,ans2;
string y;
long long x;
pair<long long,string> v[300001];
inline bool cmp(pair<long long,string> a,pair<long long,string> b){
    return a.first<b.first;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>b>>c>>a;
    cin>>m;
    aa=a;
    bb=a;
    for (int i=1;i<=m;++i){
        cin>>x>>y;
        v[i].first=x;
        v[i].second=y;
    }
    sort(v+1,v+m+1,cmp);
    for (int i=1;i<=m;++i){
        if (v[i].second=="USB" && b>0){
            --b;
            ans1++;
            ans2+=v[i].first;
        } else if (v[i].second=="PS/2" && c>0){
            --c;
            ans1++;
            ans2+=v[i].first;
        } else{
            if (v[i].second=="USB" && aa>0){
                --aa;
                ++op1;
                if (op1+op2<=a){
                    ++ans1;
                    ans2+=v[i].first;
                }
            } else if (v[i].second=="PS/2" && bb>0){
                --bb;
                ++op2;
                if (op1+op2<=a){
                    ++ans1;
                    ans2+=v[i].first;
                }
            }
        }
    }
    cout<<ans1<<" "<<ans2<<endl;
}