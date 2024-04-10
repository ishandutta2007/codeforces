#include <bits/stdc++.h>
#define db(x) cout << x << '\n';
using namespace std;

int arr[4][4];
int a[4][2];

int main()
{
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
        {
            cin >> arr[i][j];
            if(j!=3 && arr[i][j])
                a[i][0]=1,a[(i-j+3)%4][1]=1;
        }
    bool res=true;
    for(int i=0;i<4 && res;i++)
        if(arr[i][3])
            if(a[i][0] || a[i][1])
                res=false;
    if(res)
        db("NO")
    else
        db("YES")
    return 0;
}