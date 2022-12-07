#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, ar[6], an=100;
    cin>>n>>ar[2]>>ar[0];
    ar[1]=ar[0], ar[3]=ar[2], ar[4]=ar[2], ar[5]=ar[2];
    for(int a=0; a<720; a++)
    {
        int yk=0, q=0;
        while(yk<6)
        {
            int le=n;
            while(yk<6)
            {
                if(le>=ar[yk])
                {
                    le-=ar[yk], yk++;
                }
                else break;
            }
            q++;
        }
        an=min(an, q);
        next_permutation(ar, ar+6);
    }
    cout<<an;
}