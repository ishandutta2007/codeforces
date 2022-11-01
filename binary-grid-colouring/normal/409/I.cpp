#include<bits/stdc++.h>
using namespace std;
bool dfs(vector <int>* v, int start, int* used)
{
    used[start] = 1;
    for(int i = 0;i < v[start].size();i++)
    {
        if(used[v[start][i]] == 0)
        {
//            l[v[start][i]] = max(l[v[start][i]], l1 + 1);
            if(!dfs(v, v[start][i], used))
                return false;
        }
        if(used[v[start][i]] == 1)
            return false;
    }
    used[start] = 2;
    return true;
}

void bfs(vector <int>* v, int* l, int start)
{
    queue <pair <int, int> > q;
    q.push(make_pair(start, 0));
    l[start] = 0;
    while(!q.empty())
    {
        int t = q.front().first, t1 = q.front().second;
        l[t] = max(l[t], t1);
        for(int i = 0;i < v[t].size();i++)
            q.push(make_pair(v[t][i], t1 + 1));
        q.pop();
    }
}

int main()
{

    string s;
    cin >> s;
    vector <int> a;
    set <int> m;
    int i = 2;
    for(;s[i] != ')';i++)
    {
        for(;s[i] != '_';i++);
        int j = 0;
        for(;s[i] == '_';i++, j++);
        i--;
        a.push_back(j);
        m.insert(j);
    }
    vector <int>* v = new vector <int>[m.size()];
    for(;s[i] != '-';i++);
    i++;
    bool* q = new bool[m.size()];
    for(int i = 0;i < m.size();i++)
        q[i] = false;
    for(;i < s.size();i++)
    {
        for(;s[i] != '_';i++);
        int j = 0;
        for(;s[i] == '_';i++, j++);
        char c = s[i];
        i++;
        int j1 = 0;
        for(;s[i] == '_';i++, j1++);
        if(j == j1)
        {
            cout << "false"<<endl;
            return 0;
        }
        int l = 0;
        set <int>::iterator t1 = m.find(j);
        for(set <int>::iterator t = m.begin();t != t1;++t, l++);
        int l1 = 0;
        t1 = m.find(j1);
        for(set <int>::iterator t = m.begin();t != t1;++t, l1++);
        if(c == '<')
        {

            v[l].push_back(l1);
            q[l1] = true;
        }
        if(c == '>')
        {
            v[l1].push_back(l);
            q[l] = true;
        }
    }
    int* path = new int[m.size()];
    int* used = new int[m.size()];
    for(int i = 0;i < m.size();i++)
        used[i] = path[i] = 0;
    for(int i = 0;i < m.size();i++)
    {
        if(!q[i])
            if(!dfs(v, i, used))
            {
                cout << "false"<<endl;
                return 0;
            }
    }
    for(int i = 0;i < m.size();i++) {
      if(!q[i])
          bfs(v, path, i);
    }
    for(int i = 0;i < m.size();i++) {
      if(path[i] > 9)
      {
          cout << "false"<<endl;
          return 0;
      }

    }

    for(int i = 0;i < a.size();i++)
    {
        set <int>::iterator t1 = m.find(a[i]);
        int l = 0;
        for(set <int>::iterator t = m.begin();t != t1;++t, ++l);
        cout << path[l];
    }
    std::cout << '\n';
    return 0;
}