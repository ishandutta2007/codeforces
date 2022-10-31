#include <bits/stdc++.h>
using namespace std;

int n;
bool used[100005];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    if (n%4==0) {
        int l=1;
        int r=n;
        while (l<=r) {
            used[l]=used[r]=true;
            l+=2;
            r-=2;
        }
    } else if (n%4==3) {
        int x=n/4+1;
        int y=n-n/4-1;
        for (int i=x;i<=y;++i)
            used[i]=true;
    } else if (n%2==0) {
        int l=1;
        int r=n;
        while (l<=r) {
            if (r-l==1) {
                used[l]=true;
                break;
            }
            used[l]=used[r]=true;
            l+=2;
            r-=2;
        }
    } else {
        int kol=n/2;
        for (int i=n/4;i<=n/4+kol-1;++i)
            used[i]=true;
        used[n]=true;
    }
    vector<int> v;
    int s=0;
    for (int i=1;i<=n;++i)
        if (used[i]) {
            v.push_back(i);
            s+=i;
        } else s-=i;
    cout<<abs(s)<<'\n';
    cout<<v.size()<<" ";
    for (int i=0;i<v.size();++i)
        cout<<v[i]<<" ";
}