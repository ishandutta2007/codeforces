#include <bits/stdc++.h>
using namespace std;
const int sz=2e5+10;
int main()
{
    //freopen("input.txt", "r", stdin);
    int h, fo=0;
    cin>>h;
    int ar[h+1], pr[sz], pr2[sz], q=1;
    pr[0]=0, pr2[0]=0;
    for(int a=0; a<=h; a++) cin>>ar[a];
    for(int a=1; a<=h; a++)
    {
        int v=q;
        for(int b=0; b<ar[a]; b++)
        {
            pr[q]=v, pr2[q]=v, q++;
        }
        if(a>0)
        {
            if(ar[a]>1 and ar[a-1]>1)
            {
                fo=1;
                pr2[q-1]=v-1;
            }
        }
    }
    if(fo)
    {
        cout<<"ambiguous\n";
        for(int a=0; a<q; a++) cout<<pr[a]<<" ";
        cout<<"\n";
        for(int a=0; a<q; a++) cout<<pr2[a]<<" ";
    }
    else cout<<"perfect";
}