#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    string a,b;
    cin>>n;
    cin>>a>>b;
    map<char,int> c1,c2;
    for(int i=0;i<n;i++)
    {
        c1[a[i]]++;
        c2[b[i]]++;
    }
    for(char i='a';i<='z';i++)
    {
        if(c1[i]!=c2[i])
        {
            cout<<-1<<endl;
            return 0;
        }
    }
    int rem[10000],cnt=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]!=b[i])
        {
            while(a[i]!=b[i])
            {
                for(int j=i+1;j<n;j++)
                {
                    if(a[j]==b[i])
                    {
                        swap(a[j],a[j-1]);
                        rem[cnt++]=j;
                        break;
                    }
                }
            }
        }
    }
    cout<<cnt<<endl;
    if(cnt)
        cout<<rem[0];
    for(int i=1;i<cnt;i++)
    {
        printf(" %d",rem[i]);
    }
    cout<<endl;
    return 0;

}