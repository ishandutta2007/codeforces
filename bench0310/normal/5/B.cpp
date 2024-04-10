#include <iostream>

using namespace std;

int main()
{
    string s[1000];
    int idx=0,m=0;
    while(getline(cin,s[idx]))
    {
        m=max((int)s[idx].size(),m);
        idx++;
    }
    for(int i=0;i<m+2;i++) cout << '*';
    cout << endl;
    bool l=0;
    for(int i=0;i<idx;i++)
    {
        int sz=s[i].size();
        cout << '*';
        if((m&1)!=(sz&1))
        {
            if(l==0)
            {
                for(int a=0;a<(m-sz)/2;a++) cout << ' ';
                cout << s[i];
                for(int a=0;a<(m-sz+1)/2;a++) cout << ' ';
                cout << '*' << endl;
                l=1;
            }
            else
            {
                for(int a=0;a<(m-sz+1)/2;a++) cout << ' ';
                cout << s[i];
                for(int a=0;a<(m-sz)/2;a++) cout << ' ';
                cout << '*' << endl;
                l=0;
            }
        }
        else
        {
            for(int a=0;a<(m-sz)/2;a++) cout << ' ';
            cout << s[i];
            for(int a=0;a<(m-sz+1)/2;a++) cout << ' ';
            cout << '*' << endl;
        }
    }
    for(int i=0;i<m+2;i++) cout << '*';
    cout << endl;
    return 0;
}