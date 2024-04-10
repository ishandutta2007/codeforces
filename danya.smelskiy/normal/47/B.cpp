#include <bits/stdc++.h>
using namespace std;

string s[5];
int a[5][5];

int main(){
    for (int i=1;i<=3;++i)
        cin>>s[i];
    for (int i=1;i<=3;++i){
        int x=s[i][0]-'A'+1;
        int y=s[i][2]-'A'+1;
        if (s[i][1]=='>') a[x][y]=1;
        else a[y][x]=1;
    }
    for (int i=1;i<=3;++i)
        for (int j=1;j<=3;++j)
        if (i!=j)
            for (int z=1;z<=3;++z)
    if (z!=i && z!=j){
        if (a[i][j]==1 && a[j][z]==1 && a[z][i]==1){
            cout<<"Impossible";
            return 0;
        }
    }
    for (int i=1;i<=3;++i)
        for (int j=1;j<=3;++j)
        for (int z=1;z<=3;++z)
    if (i!=j && j!=z && z!=i){
        if (a[i][j]==1 && a[i][z]==1 && a[j][z]==1) {
            cout<<char(z+'A'-1)<<char(j+'A'-1)<<char(i+'A'-1);
            return 0;
        }
    }
}