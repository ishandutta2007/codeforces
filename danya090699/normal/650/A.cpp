#include <iostream>
#include <fstream>
#include <algorithm>
#define int long long
using namespace std;
bool comp(int *a, int *b)
{
    if(a[0]!=b[0]) return (a[0]<b[0]);
    else return (a[1]<b[1]);
}
bool comp2(int *a, int *b){return (a[1]<b[1]);}
main()
{
    //ifstream in("input.txt");
    int n;
    cin>>n;
    int *ar[n], an=0;
    for(int a=0; a<n; a++)
    {
        ar[a]=new int[2];
        cin>>ar[a][0]>>ar[a][1];
    }
    sort(ar, ar+n, comp2);
    int yk=0;
    while(yk<n)
    {
        int st=yk, cu=ar[yk][1];
        while(yk<n)
        {
            if(ar[yk][1]==cu) yk++;
            else break;
        }
        int q=yk-st;
        an+=q*(q-1)/2;
    }
    sort(ar, ar+n, comp);
    yk=0;
    while(yk<n)
    {
        int st=yk, cu=ar[yk][0];
        while(yk<n)
        {
            if(ar[yk][0]==cu) yk++;
            else break;
        }
        int q=yk-st;
        an+=q*(q-1)/2;
    }
    yk=0;
    while(yk<n)
    {
        int st=yk, cux=ar[yk][0], cuy=ar[yk][1];
        while(yk<n)
        {
            if(cux==ar[yk][0] and cuy==ar[yk][1]) yk++;
            else break;
        }
        int q=yk-st;
        an-=q*(q-1)/2;
    }
    cout<<an;
}