#include <bits/stdc++.h>


using namespace std;

typedef long long ll;
typedef long double ld;

int n,sum;

void second() {
    int x=sum;
    for(int i=1;i<=n;i++) {
        int t=min(x,9);
        cout<<t;
        x-=t;
    }
}

void first()  {
    if(n==1) {
        cout<<sum;
        return;
    }
    /// x 999999
    for(int cif=1;cif<=9;cif++) {
        if(cif+9*(n-1)==sum) {
            cout<<cif;
            for(int j=1;j<n;j++) {
                cout<<"9";
            }
            return;
        }
    }
    /// 1 0000 x 9999999
    int x=(sum-1)%9;
    for(int cnt=0;cnt<=n;cnt++) {
        if(cnt*9+x+1==sum) {
            cout<<1;
            for(int i=1;i<=n-cnt-2;i++) {
                cout<<0;
            }
            cout<<x;
            for(int i=1;i<=cnt;i++) {
                cout<<9;
            }
            return;
        }
    }

}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>sum;
    if(n==1) {
        if(0<=sum && sum<=9) {
            cout<<sum<<" "<<sum<<"\n";
        }
        else {
            cout<<"-1 -1\n";
        }
        return 0;
    }
    if(sum==0 || sum>9*n) {
        cout<<"-1 -1\n";
        return 0;
    }
    first(); cout<<" ";
    second();
    return 0;
}
/**

**/