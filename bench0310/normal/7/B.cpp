#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int t,m;
    cin >> t >> m;
    int b[m];
    for(int i=0;i<m;i++) b[i]=0;
    int id=1;
    string s;
    int num;
    for(int a=0;a<t;a++)
    {
        cin >> s;
        if(s[0]=='a')
        {
            cin >> num;
            int idx=0;
            bool done=0;
            while(idx<=m-num+1)
            {
                bool good=1;
                for(int i=idx;i<idx+num;i++)
                {
                    if(b[i])
                    {
                        good=0;
                        idx=i+1;
                        break;
                    }
                }
                if(good)
                {
                    done=1;
                    cout << id << endl;
                    for(int i=idx;i<idx+num;i++) b[i]=id;
                    id++;
                    break;
                }
            }
            if(!done) cout << "NULL" << endl;
        }
        else if(s[0]=='e')
        {
            cin >> num;
            bool found=0;
            for(int i=0;i<m;i++)
            {
                if(b[i]==num)
                {
                    if(num) found=1;
                    b[i]=0;
                }
            }
            if(!found) cout << "ILLEGAL_ERASE_ARGUMENT" << endl;
        }
        else
        {
            vector<int> v;
            for(int i=0;i<m;i++)
            {
                if(b[i]) v.push_back(b[i]);
            }
            for(int i=0;i<(int)v.size();i++) b[i]=v[i];
            for(int i=(int)v.size();i<m;i++) b[i]=0;
        }
    }
    return 0;
}