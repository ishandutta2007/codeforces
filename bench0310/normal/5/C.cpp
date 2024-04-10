#include <iostream>
#include <stack>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int sz=s.size();
    int d[sz]; //Corresponding open bracket, -1 if it doesn't exist
    int c[sz]; //Position of the earliest open bracket so that c[i]..i is a regular sequence
    stack<int> b;
    int len=0,num=0;
    for(int i=0;i<sz;i++)
    {
        if(s[i]=='(')
        {
            d[i]=c[i]=-1;
            b.push(i);
        }
        else
        {
            if(b.empty()) d[i]=c[i]=-1;
            else
            {
                d[i]=b.top();
                b.pop();
                if(d[d[i]-1]!=-1&&d[i]) c[i]=c[d[i]-1];
                else c[i]=d[i];
            }
        }
        if(c[i]!=-1)
        {
            if((i-c[i]+1)>len)
            {
                len=(i-c[i]+1);
                num=1;
            }
            else if((i-c[i]+1)==len) num++;
        }
    }
    if(len==0) num=1;
    cout << len << " " << num << endl;
    return 0;
}