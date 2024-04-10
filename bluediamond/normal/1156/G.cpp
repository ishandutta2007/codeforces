#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
bool home=1;

const int N=12345;
int n;
vector<int> g[N];
string name[N];

map<string, int> lastId;

void upd(string s){
        n++;
        lastId[s]=n;
        name[n]=s;
}

mt19937 rng((long long)(new char));

set<string> used;

vector<string> all;

map<int,string>wat;

string request(int id,bool is_res){
        if(wat.count(id)){
               /// cout<<"ma cherie : "<<id<<"\n";
                return wat[id];
        }
        if(g[id].empty()){
                return name[id];
        }
        assert((int)g[id].size()==3);
        int id1=g[id][0];
        int op=g[id][1];
        int id2=g[id][2];
        string current;
        if(is_res)current="res";
        else{
                string wa;
                bool fo=0;
                for(char c0='a';c0<='z'&&!fo;c0++)
                for(char c1='a';c1<='z'&&!fo;c1++)
                for(char c2='a';c2<='z'&&!fo;c2++)
                for(char c3='a';c3<='z'&&!fo;c3++){
                        string tog;tog+=c0;tog+=c1;tog+=c2;tog+=c3;
                        if(!used.count(tog))wa=tog,fo=1;
                }
                assert(fo);
                assert(!used.count(wa));
                used.insert(wa);
                current=wa;
        }

        char chz=op;
        string lolz; lolz+=chz;
        string r=request(id1,0);
        string r2=request(id2,0);

        string money=current+"="+r+lolz+r2;
        all.push_back(money);
        wat[id]=current;
        return current;
}


signed main() {
#ifdef ONLINE_JUDGE
          home = 0;
#endif

        if (home) {
                freopen("iron_man.txt", "r", stdin);
        }
        else {
                ios::sync_with_stdio(0); cin.tie(0);
        }


        int ofs;
        set<char> ops;

        ops.insert('$');
        ops.insert('^');
        ops.insert('#');
        ops.insert('&');

        cin>>ofs;
        map<vector<int>,int>memo;

        set<vector<int>> deja;

        for(int step=1;step<=ofs;step++){
                string s;
                cin>>s;
                vector<int> w_eq;
                vector<int> w_ops;
                for(int i=0;i<(int)s.size();i++){
                        if(s[i]=='='){
                                w_eq.push_back(i);
                        }
                        if(ops.count(s[i])){
                                w_ops.push_back(i);
                        }
                }
                assert((int)w_eq.size()==1);
                assert((int)w_ops.size()==0||(int)w_ops.size()==1);
                int pos_eq=w_eq[0];
                if((int)w_ops.size()==0){
                        string a,b;
                        for(int i=0;i<pos_eq;i++) a+=s[i];
                        for(int i=pos_eq+1;i<(int)s.size();i++) b+=s[i];


                        used.insert(a);
                        used.insert(b);

                        if(!lastId.count(b)) upd(b);
                        lastId[a]=lastId[b];
                   ///     cout<<"lol\n";
                }else{
                        assert((int)w_ops.size()==1);
                        int pos_op=w_ops[0];
                        assert(pos_eq<pos_op);
                        string a,b,c,op;
                        op=s[pos_op];
                        for(int i=0;i<pos_eq;i++) a+=s[i];
                        for(int i=pos_eq+1;i<pos_op;i++) b+=s[i];
                        for(int i=pos_op+1;i<(int)s.size();i++) c+=s[i];



                        used.insert(a);
                        used.insert(b);
                        used.insert(c);


                        if(!lastId.count(b)) upd(b);
                        if(!lastId.count(c)) upd(c);
                        int before_b=lastId[b];
                        int before_c=lastId[c];


                        vector<int> tog={before_b,op[0],before_c};

///                        cout<<"\t\t\t"<<before_b<<" and "<<before_c<<"\n";

                        if(!deja.count(tog)){
                                upd(a);
                                g[lastId[a]]=tog;
                                memo[tog]=lastId[a];
                                deja.insert(tog);
                        }else{
                     ///           cout<<"ici\n";
                                lastId[a]=memo[tog];
                        }

                }
        }
        if(!lastId.count("res")){
                cout<<"0\n";
                return 0;
        }
        int res_id=lastId["res"];
        request(res_id,1);
        if(all.empty()&&name[lastId["res"]]!="res"){
                cout<<"1\n";
                cout<<"res="<<name[lastId["res"]]<<"\n";
                return 0;
        }
        cout<<(int)all.size()<<"\n";
        for(auto&s:all){
                cout<<s<<"\n";
        }

}