#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int t,n,a[101],dem=0;
    cin >> t;
    for(int k=0;k<t;k++)
    {
        int dem=0,tam=0,c=0;
        cin >> n;
        for(int l=1;l<=n;l++)
        {
            cin >> a[l];
            if(a[l]==0) c++;
        }
        if(c!=0)dem=n-c;
        else
        {
            sort(a+1,a+n+1);
            int i=1,j=i+1;
            for(;j<=n;i++,j++)
                if(a[i]==a[j])
                {
                    c=1;
                    dem++;
                    break;
                }
            i=1;j=i+1;
            if(c==1)dem+=n-c;
            else
            while(i<=n)
            {
                if(a[j]<a[i]||a[i]<a[j])
                {
                    tam=min(a[i],a[j]);
                    a[i]=tam;
                    a[j]=tam;
                    dem++;
                }
                else if(a[i]==a[j] && a[i]!=0)
                {
                    a[i]=0;
                    dem++;
                }
                else if(a[i]==a[j] && a[i]==0)
                {
                    dem+=n-2;
                    break;
                }
            }
        }
        cout << dem << endl;
    }
    return 0;
}