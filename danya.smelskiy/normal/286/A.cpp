#include <bits/stdc++.h>
using namespace std;

int n;
bool used[100005];
int a[100005];

void recurs(int x) {
    if (used[x]) return;
    used[x]=true;
    a[a[x]]=n-x+1;
    recurs(a[x]);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    if (n==1) {
        cout<<"1";
        return 0;
    }
    if (n%4>1) {
        cout<<"-1";
        return 0;
    }
    if (n%2==0) {
        for (int i=1;i<=n/2;i+=2) {
            a[i]=i+1;
            recurs(i);
        }
    } else if (n%4==3) {
        for (int i=1;i<=(n+1)/2;i+=2) {
            if (i==n/2) {
                a[i]=i+2;
                a[i+2]=i;
                a[i+1]=i+1;
                break;
            }
            a[i]=i+1;
            recurs(i);
        }
    } else {
        for (int i=1;;i+=2) {
            if (i==n/2-1) {
                a[i]=i+1;
                a[i+1]=i+4;
                a[i+2]=i+2;
                a[i+3]=i;
                a[i+4]=i+3;
                break;
            } else {
                a[i]=i+1;
                recurs(i);
            }
        }
    }
    for (int i=1;i<=n;++i)
        cout<<a[i]<<" ";
}