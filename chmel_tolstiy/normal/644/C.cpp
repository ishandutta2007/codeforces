#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

void solve() {
    typedef vector<string> paths;
    map<string, paths> servers;
    
    int n;
    cin >> n;
    
    for (int i = 0; i < n; ++i) {
        string page;
        cin >> page;
        string prefix = page.substr(0, page.find(':') + 3);
        page = page.substr(prefix.length());
        
        if (page.find('/') != string::npos) {
            string host = prefix + page.substr(0, page.find('/'));
            string path = page.substr(page.find('/'));
            servers[host].push_back(path);
        } else {
            string host = prefix + page;
            servers[host].push_back("");
        }
    }
    
    map< paths, vector<string> > duplicates;
    int cnt = 0;
    
    for (map<string, paths>::iterator it = servers.begin(); it != servers.end(); ++it) {
        paths p = it->second;
        sort(p.begin(), p.end());
        p.resize(unique(p.begin(), p.end()) - p.begin());
        duplicates[p].push_back(it->first);
        if (duplicates[p].size() == 2)
            ++cnt;
    }
    
    cout << cnt << endl;
    
    for (map< paths, vector<string> >::iterator it = duplicates.begin();
                it != duplicates.end(); ++it) {
                  if (it->second.size() > 1) {
                      vector<string> sr = it->second;
                      for (int i = 0; i < sr.size(); ++i) {
                          if (i) cout << ' ';
                          cout << sr[i];
                      }
                      cout << endl;
                  }  
                }
}

int main() {
    solve();
    return 0;
}