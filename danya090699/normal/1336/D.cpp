#include <bits/stdc++.h>
using namespace std;
main()
{
    int n, q1, q2;
    cin>>n>>q1>>q2;
    int d1[n], d2[n], an[n];
    for(int a=0; a<n; a++)
    {
        int p;
        if(a<n-3) p=n-1-a;
        else if(a==n-3) p=1;
        else if(a==n-2) p=2;
        else if(a==n-1) p=1;
        cout<<"+ "<<p<<"\n";
        int nq1, nq2;
        cin>>nq1>>nq2;
        d1[a]=nq1-q1, d2[a]=nq2-q2;
        q1=nq1, q2=nq2;
    }
    an[0]=0;
    while(an[0]*(an[0]+1)/2<d1[n-1]) an[0]++;
    an[2]=d2[n-1]-d2[n-3]-1;
    an[1]=d2[n-3]/(an[2]+1);

    an[3]=(d2[n-2]-(an[0]+1)*(an[2]+1))/(an[2]+1)-1;

    for(int a=4; a<n; a++)
    {
        an[a]=(d2[n-a]-an[a-3]*an[a-4]-(an[a-1]+1)*an[a-3])/(an[a-1]+1)-1;
    }
    an[n-1]++;

    cout<<"!";
    for(int a=0; a<n; a++) cout<<" "<<an[a];
    cout<<"\n";
}