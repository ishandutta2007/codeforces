#include<algorithm>
#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstring>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int n = (int)s.size();
    int col1 = 0;
    int col2 = 0;
    int col3 = 0;
    for(int i = 0; i < n; i++)
    {
        if(s[i] == '(')
            col1++;
        else if(s[i] == ')')
            col2++;
        else
            col3++;
    }
    if(col2 + col3 > col1)
    {
        cout << "-1";
        return 0;
    }
    int a = col1 - col2 - col3 + 1;
    col1 = 0;
    col2 = 0;
    int coll3 = 0;
    bool d = 1;
    for(int i = 0; i < n; i++)
    {
        if(s[i] == '(')
        {
            col1++;
        }
        else if(s[i] == ')')
        {
            col2++;
        }
        else
        {
            coll3++;
            if(coll3 < col3)
                col2++;
            else
                col2 += a;
        }
        if(col1 < col2)
        {
            cout << "-1";
            return 0;
        }
    }
    for(int i = 1; i < col3; i++)
        cout << "1\n";
    cout << a;
    return 0;
}