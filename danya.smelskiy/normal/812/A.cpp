#include <bits/stdc++.h>
using namespace std;

int a[10][10];

inline void no(){
    cout<<"YES";
    exit(0);
}
inline void chek(int x,int y){
    if (x && a[y][4]) no();
}
int main(){
    for (int i=1;i<=4;++i)
        for (int j=1;j<=4;++j)
        cin>>a[i][j];
    for (int i=1;i<=4;++i) {
        int k=0;
        for (int j=1;j<=3;++j)
            k+=a[i][j];
        if (k && a[i][4]) no();
    }
    chek(a[1][2],3);
    chek(a[1][3],2);
    chek(a[1][1],4);
    chek(a[2][1],1);
    chek(a[2][2],4);
    chek(a[2][3],3);
    chek(a[3][1],2);
    chek(a[3][2],1);
    chek(a[3][3],4);
    chek(a[4][1],3);
    chek(a[4][2],2);
    chek(a[4][3],1);
    cout<<"NO";
}