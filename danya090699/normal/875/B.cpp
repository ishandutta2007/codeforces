#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    bool us[n];
    stack <int> st;
    for(int a=0; a<n; a++)
    {
        us[a]=0, st.push(a);
    }
    printf("%d ", 1);
    for(int a=0; a<n; a++)
    {
        int x;
        scanf("%d", &x);
        us[x-1]=1;
        while(st.size()>0)
        {
            if(us[st.top()]) st.pop();
            else break;
        }
        int an=(a+1)-(n-st.size())+1;
        printf("%d ", an);
    }
}