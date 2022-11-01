#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    vector<int> one,two;
    for(int i=0;i<n;i++)
    {
        int t,w;
        scanf("%d%d",&t,&w);
        if(t==1) one.push_back(w);
        else two.push_back(w);
    }
    int a=one.size();
    int b=two.size();
    sort(one.begin(),one.end());
    sort(two.begin(),two.end());
    vector<int> sumone(a+1,0);
    vector<int> sumtwo(b+1,0);
    for(int i=1;i<=a;i++) sumone[i]=sumone[i-1]+one[i-1];
    for(int i=1;i<=b;i++) sumtwo[i]=sumtwo[i-1]+two[i-1];
    int res=2*n;
    for(int o=0;o<=a;o++)
    {
        for(int i=0;i<=(int)b;i++)
        {
            if((a-o)+2*(b-i)>=sumone[o]+sumtwo[i]) res=min(res,(a-o)+2*(b-i));
        }
    }
    printf("%d\n",res);
    return 0;
}