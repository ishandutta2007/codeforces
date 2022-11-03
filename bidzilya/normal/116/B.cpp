#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

char map[10][10];

int main(){
    int n,m;
    cin >> n >> m;
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
            cin >> map[i][j];
    int ans =0;
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
            if (map[i][j]=='W')
                if ((i>0 && map[i-1][j]=='P')||
                    (j>0 && map[i][j-1]=='P')||
                    (j+1<m && map[i][j+1]=='P')||
                    (i+1<n && map[i+1][j]=='P'))
                        ans++;
    cout << ans;
    return 0;
}