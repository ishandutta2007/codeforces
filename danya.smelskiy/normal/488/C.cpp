#include <bits/stdc++.h>
using namespace std;


int ans=1e9;
int price[5];
int a[3][4];
inline bool chek(int x,int y,int z){
    int atk1=max(0,y-a[2][3]);
    int atk2=max(0,a[2][2]-z);
    if (atk1==0) return false;
    if (atk2==0) return true;
    int t1=(a[2][1]+atk1-1)/atk1;
    int t2=(x+atk2-1)/atk2;
    return t1<t2;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //hp atk def
    for (int i=1;i<=2;++i)
        for (int j=1;j<=3;++j)
        cin>>a[i][j];
    for (int i=1;i<=3;++i)
        cin>>price[i];
    if (chek(a[1][1],a[1][2],a[1][3])) {
        cout<<"0";
        return 0;
    }
    for (int i=0;i<=10000;++i) {
        for (int j=a[1][3];j<=100;++j) {
            int l=0;
            int r=10000;
            while (l<r-1) {
                int mid=(l+r)>>1;
                if (chek(a[1][1]+i,a[1][2]+mid,j)) r=mid;
                else l=mid;
            }
            if (chek(a[1][1]+i,a[1][2]+l,j)) r=l;
            if (chek(a[1][1]+i,a[1][2]+r,j)) ans=min(ans,i*price[1]+(j-a[1][3])*price[3]+r*price[2]);
        }
    }
    cout<<ans;
}