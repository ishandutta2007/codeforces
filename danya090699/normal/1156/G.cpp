#include <bits/stdc++.h>
using namespace std;

map <string, string> var, form, val;
set <string> us;
vector <string> ans;
void dfs(string name)
{
    us.insert(name);
    string va=var[name];
    for(int a=0; a<va.size(); a++)
    {
        if(va[a]=='$' or va[a]=='^' or va[a]=='#' or va[a]=='&')
        {
            string l=va.substr(0, a), r=va.substr(a+1, va.size()-1-a);
            if(us.find(l)==us.end()) dfs(l);
            if(us.find(r)==us.end()) dfs(r);
            ans.push_back(name+"="+va);
            break;
        }
    }
}
int yk=0;
string new_var()
{
    while(1)
    {
        int x=yk;
        string cu;
        for(int i=0; i<4; i++)
        {
            cu.push_back('a'+x%26), x/=26;
        }
        if(var.find(cu)==var.end()) return cu;
        else yk++;
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    vector <string> sp[n];
    for(int a=0; a<n; a++)
    {
        string str;
        cin>>str;
        int p1, p2=-1;
        for(int b=0; b<str.size(); b++)
        {
            if(str[b]=='=') p1=b;
            if(str[b]=='$' or str[b]=='^' or str[b]=='#' or str[b]=='&') p2=b;
        }
        string var1=str.substr(0, p1), var2, var3, op;
        if(p2!=-1)
        {
            var2=str.substr(p1+1, p2-p1-1);
            op=str.substr(p2, 1);
            var3=str.substr(p2+1);
        }
        else var2=str.substr(p1+1);

        sp[a].push_back(var1), var[var1]=var1;
        sp[a].push_back(var2), var[var2]=var2;

        if(p2!=-1)
        {
            var[var3]=var3;
            sp[a].push_back(op), sp[a].push_back(var3);
        }
    }
    var["res"]="res";
    for(auto it=var.begin(); it!=var.end(); it++)
    {
        string cu=(*it).first;
        form[cu]=cu, val[cu]=cu;
    }
    for(int a=0; a<n; a++)
    {
        string lva=sp[a][0], rva;
        if(sp[a].size()==2) rva=val[sp[a][1]];
        else
        {
            string f=val[sp[a][1]]+sp[a][2]+val[sp[a][3]];

            if(form.find(f)!=form.end()) rva=form[f];
            else
            {
                string nvar=new_var();
                var[nvar]=f, form[f]=nvar, val[nvar]=nvar;
                rva=nvar;
            }
        }
        val[lva]=rva;
    }
    if(val["res"]!="res")
    {
        string x=val["res"];
        int p=-1;
        for(int a=0; a<var[x].size(); a++)
        {
            if(var[x][a]=='$' or var[x][a]=='^' or var[x][a]=='#' or var[x][a]=='&') p=a;
        }
        if(p==-1) ans.push_back("res="+x);
        else
        {
            dfs(x);
            ans.back()="res"+ans.back().substr(x.size());
        }
    }
    cout<<ans.size()<<"\n";
    for(int a=0; a<ans.size(); a++) cout<<ans[a]<<"\n";
}