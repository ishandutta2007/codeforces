#include<iostream>
using namespace std;
#define min(a,b) a<b?a:b
#define max(a,b) a>b?a:b
int main(){
    int lx=1000,ly=1000,rx=0,ry=0;
    char map[550][550];
    int m,n;
    cin>>n>>m;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++){
            cin>>map[i][j];
            if (map[i][j]=='X'){
                lx=min(lx,i);
                ly=min(ly,j);
                rx=max(rx,i);
                ry=max(ry,j);
            }
        }
        for (int i=lx;i<=rx;i++)
            for (int j=ly;j<=ry;j++)
                if (map[i][j]!='X'){
                    cout<<"NO";
                    return 0;
                }
    cout<<"YES";
    return 0;
}