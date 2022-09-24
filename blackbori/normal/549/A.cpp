#include <bits/stdc++.h>

using namespace std;

string s[60];

bool F(int x,int y)
{
    int i,j;
    int f[5] = {0,1,1,1,1};
    for(i=x-1; i<=x; i++){
        for(j=y-1; j<=y; j++){
            switch (s[i][j]){
            case 'f':
                f[1]--;
                break;
            case 'a':
                f[2]--;
                break;
            case 'c':
                f[3]--;
                break;
            case 'e':
                f[4]--;
                break;
            }
        }
    }

    if(f[1] == 0 && f[2] == 0 && f[3] == 0 && f[4] == 0) return true;

    return false;
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int i,j,n,m,sum=0;

    scanf("%d %d",&n,&m);

    for(i=0; i<n; i++){
        cin >> s[i];
    }

    for(i=1; i<n; i++){
        for(j=1; j<m; j++){
            sum += F(i,j);
        }
    }

    printf("%d\n",sum);

    return 0;
}