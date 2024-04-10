#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    multiset <int, greater <int> > lx, ly;
    multiset <int> rx, ry;
    int ar[n][4];
    for(int a=0; a<n; a++)
    {
        for(int b=0; b<4; b++) scanf("%d", &ar[a][b]);
        lx.insert(ar[a][0]);
        rx.insert(ar[a][2]);
        ly.insert(ar[a][1]);
        ry.insert(ar[a][3]);
    }
    for(int a=0; a<n; a++)
    {
        int x1=ar[a][0], x2=ar[a][2], y1=ar[a][1], y2=ar[a][3];
        lx.erase(lx.find(x1)), rx.erase(rx.find(x2));
        ly.erase(ly.find(y1)), ry.erase(ry.find(y2));
        int lgx=*(lx.begin()), rgx=*(rx.begin()), lgy=*(ly.begin()), rgy=*(ry.begin());
        //cout<<lgx<<" "<<rgx<<"\n";
        if(lgx<=rgx and lgy<=rgy)
        {
            cout<<lgx<<" "<<lgy;
            break;
        }
        lx.insert(x1);
        rx.insert(x2);
        ly.insert(y1);
        ry.insert(y2);
    }
}