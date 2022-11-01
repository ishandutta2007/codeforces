#include <bits/stdc++.h>

using namespace std;

int main()
{
    char t[1000001];
    scanf("%s",t);
    int n=strlen(t);
    auto one=[](char c)->bool
    {
        return (c=='<'||c=='{'||c=='['||c=='(');
    };
    auto two=[](char c)->char
    {
        if(c=='<') return '>';
        if(c=='{') return '}';
        if(c=='[') return ']';
        if(c=='(') return ')';
        return '0';
    };
    int a=0;
    int res=0;
    stack<char> s;
    for(int i=0;i<n;i++)
    {
        if(one(t[i]))
        {
            a++;
            s.push(t[i]);
        }
        else
        {
            a--;
            if(a==-1)
            {
                printf("Impossible\n");
                return 0;
            }
            res+=(two(s.top())!=t[i]);
            s.pop();
        }
    }
    if(a==0) printf("%d\n",res);
    else printf("Impossible\n");
    return 0;
}