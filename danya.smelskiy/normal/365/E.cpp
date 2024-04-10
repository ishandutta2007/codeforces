#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> ans;
int a[10];
inline bool cmp(int a,int b){
    return a>b;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    a[1]=2; a[2]=3; a[3]=5; a[4]=7; a[5]=11; a[6]=13; a[7]=17;
    for (int i=1;i<=7;++i) {
        ans.clear();
        ans.push_back(1);
        for (int k=1;k<=i;++k) {
            int kol=ans.size();
            for (int j=0;j<kol;++j) {
                int x=ans[j];
                while (x*a[k]<=2*n*n) {
                    x*=a[k];
                    ans.push_back(x);
                }
            }
        }
        if (ans.size()>n) break;
    }
    sort(ans.begin(),ans.end(),cmp);
    for (int i=0;i<n;++i)
        cout<<ans[i]<<" ";
}