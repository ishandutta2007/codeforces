#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    lli n,m,k;
    cin>>n>>m>>k;
    lli ma=4*n*m-2*n-2*m;
    if(ma<k){
        cout<<"NO\n";
        return 0;
    }
    else{
        cout<<"YES\n";
        map<string,string> sw;
        sw["R"]="R";
        sw["U"]="U";
        sw["D"]="D";
        sw["L"]="L";
        if(n>m){
            swap(n,m);
            sw["R"]="D";
            sw["L"]="U";
            sw["D"]="R";
            sw["U"]="L";
        }
            vector<pair<lli,string>> moves;
            lli tot=0;
            bool done=false;
            if(tot+m-1>=k){
                moves.push_back({k,sw["R"]});
                done=true;
            }
            else{
                if(m-1)moves.push_back({m - 1, sw["R"]});
                tot += m - 1;
            }
            if(!done){
                if(tot+m-1>=k){
                    moves.push_back({k-tot,sw["L"]});
                    done=true;
                }
                else{
                    if(m-1)moves.push_back({m - 1, sw["L"]});
                    tot += m - 1;
                }
            }
            if(!done){
                for(int i=1;i<n&&!done;i++){
                    if(tot+1>=k)moves.push_back({k-tot,sw["D"]}),done=true;
                    else{
                        moves.push_back({1,sw["D"]});
                        tot+=1;
                    }
                    if(!done){
                        if(tot+(m-1)*3>=k){
                            lli team=(k-tot)/3;
                            if(team)moves.push_back({team,sw["R"]+sw["U"]+sw["D"]});
                            tot+=team*3;
                            if(tot<k){
                                moves.push_back({1,sw["R"]});
                                tot+=1;
                            }
                            if(tot<k){
                                moves.push_back({1,sw["U"]});
                                tot+=1;
                            }
                            done=true;
                        }
                        else{
                            if(m>1)moves.push_back({m - 1, sw["R"]+sw["U"]+sw["D"]});
                            tot += (m - 1)*3;
                        }
                        if(!done){
                            if(tot+m-1>=k){
                                moves.push_back({k-tot,sw["L"]});
                                done=true;
                            }
                            else{
                                if(m-1)moves.push_back({m - 1, sw["L"]});
                                tot += m - 1;
                            }
                        }
                    }
                }
            }
            if(!done){
                moves.push_back({k-tot, sw["U"]});
            }
            cout<<(int)moves.size()<<"\n";
            for(auto x:moves){
                cout<<x.first<<" "<<x.second<<"\n";
            }
    }
    return 0;
}