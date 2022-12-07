#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    char sy=92;
    string s;
    vector <string> sp;
    while(cin>>s)
    {
        string fi;
        fi.push_back(sy);
        fi+="begin{thebibliography}{99}";
        if(s==fi) break;

        if(s.size()>6)
        {

            string fi;
            fi.push_back(sy);
            fi+="cite{";
            if(s.substr(0, 6)==fi)
            {

                string cu;
                int yk=6;
                while(s[yk]!='}') cu.push_back(s[yk]), yk++;
                sp.push_back(cu);
                //cout<<cu<<"\n";
            }
        }
    }

    int b=0, n=sp.size(), ok=1;
    string an[n];
    getline(cin, s);
    while(getline(cin, s))
    {
        string fi;
        fi.push_back(sy);
        fi+="end{thebibliography}";

        if(s==fi) break;

        string cu;
        int yk=9;
        while(s[yk]!='}') cu.push_back(s[yk]), yk++;
        for(int a=0; a<n; a++)
        {
            if(cu==sp[a])
            {
                an[a]=s;
                if(a!=b) ok=0;
            }
        }
        b++;
    }
    if(ok) cout<<"Correct";
    else
    {
        cout<<"Incorrect\n";

        string fi;
        fi.push_back(sy);

        cout<<fi<<"begin{thebibliography}{99}\n";
        for(int a=0; a<n; a++) cout<<an[a]<<"\n";
        cout<<fi<<"end{thebibliography}";
    }
}