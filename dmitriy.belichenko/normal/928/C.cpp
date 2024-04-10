

    #include <iostream>
    #include <vector>
    #include <algorithm>
    #include <string>
    #include <map>
    #include <math.h>
    #include <iomanip>

    using namespace std;
    long long int n,d,k;
    vector <string> v1;
    vector <string> v2;
    string s;
    vector <long long  > v;
    pair < string, int> main_pr;
    map<pair < string, int> ,vector < pair < string, int> >> mp;

    map <  string, int > used;
    map <  string, int > maxv;


    vector <pair < pair < string, int >, int > > depends;
    vector < pair < string, int > > depends_ans;


    vector < pair < string, int > > now;
    vector <  string > now1;


    int main()
    {
        cin >> n;
        string main_s;
        int vers_main;
        for(int i =0; i < n; i++)
        {
            string s;
            int vers;
            cin >> s >> vers;
            used[s] = 0;
            maxv[s] = -1;
            if(i == 0)
            {
                main_s = s;
                vers_main = vers;
                main_pr = {s,vers};
            }
            pair < string, int> p,q;
            p = {s,vers};
            cin >> k;
            for(int j =0; j < k; j++)
            {
                string s1;
                int vers1;
                cin >> s1 >> vers1;
                q = {s1,vers1};
                mp[p].push_back(q);
            }

        }
        now.push_back(main_pr);

        while(now.size() > 0)
        {
            now1.clear();

            for(int i =0; i < now.size(); i++)
            {
                used[now[i].first] = 1;
                if(now[i].first  != main_pr.first)
                depends_ans.push_back(now[i]);
                for(int j =0; j < mp[now[i]].size(); j++ )
                {
                            if (used[mp[ now[i] ][j].first] == 0){
                                now1.push_back(mp[ now[i] ][j].first);
                                used[mp[ now[i] ][j].first] = 1;
                            }
                        maxv[mp[ now[i] ][j].first] = max(maxv[mp[ now[i] ][j].first],mp[ now[i] ][j].second );

                }
            }
            now.clear();
            for(int i =0; i < now1.size(); i++)
            {
                now.push_back({now1[i], maxv[now1[i]]});
            }

        }

        cout << endl << depends_ans.size() << endl;
        sort(depends_ans.begin(), depends_ans.end() );
        for(int i = 0; i < depends_ans.size(); i++)
        {
            cout << depends_ans[i].first << ' ';
            cout << depends_ans[i].second<< endl;
        }


    }