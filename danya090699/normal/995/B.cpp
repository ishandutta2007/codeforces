#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    int ar[2*n], q=0;
    for(int a=0; a<2*n; a++) cin>>ar[a];
    for(int a=0; a<2*n; a++)
    {
        int fo=-1;
        for(int b=a+1; b<2*n; b++) if(ar[b]==ar[a]) fo=b;
        if(fo!=-1)
        {
            for(int b=fo-1; b>a; b--)
            {
                swap(ar[b], ar[b+1]), q++;
            }
        }
    }
    cout<<q;
}