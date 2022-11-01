#include <iostream>
#include <map>
#include <set>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    map<string,int> m;
    string name[n];
    int score[n];
    for(int i=0;i<n;i++)
    {
        cin >> name[i] >> score[i];
        if(m.find(name[i])==m.end())  m.insert(make_pair(name[i],score[i]));
        else m[name[i]]+=score[i];
    }
    int best=-10000000;
    set<string> s;
    for(map<string,int>::iterator it=m.begin();it!=m.end();it++)
    {
        if(it->second>best)
        {
            s.clear();
            s.insert(it->first);
            best=it->second;
        }
        else if(it->second==best)
        {
            s.insert(it->first);
        }
    }
    map<string,int> e;
    for(int i=0;i<n;i++)
    {
        if(e.find(name[i])==e.end())  e.insert(make_pair(name[i],score[i]));
        else e[name[i]]+=score[i];
        if(e[name[i]]>=best&&s.count(name[i]))
        {
            cout << name[i] << endl;
            break;
        }
    }
    return 0;
}