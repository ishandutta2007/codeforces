#include <bits/stdc++.h>
#define int long long
using namespace std;
int counts[26];
int32_t main(){
    ios_base::sync_with_stdio(false);
    int tc;
    cin>>tc;
    for(int ct=0;ct<tc;++ct){
        string str;
        cin>>str;
        for(char ch:str){
            counts[ch-'a']++;
        }
        int first=find_if_not(counts,counts+26,[](int x){return x==0;})-counts;
        int second=find_if_not(counts+first+1,counts+26,[](int x){return x==0;})-counts;
        if(second==26){
            // all same
            for(int i=0;i<counts[first];++i)cout<<(char)('a'+first);
        }
        else{
            int first_unique=find_if(counts,counts+26,[](int x){return x==1;})-counts;
            if(first_unique!=26){
                cout<<(char)('a'+first_unique);
                --counts[first_unique];
                for(int i=0;i<26;++i){
                    for(int j=0;j<counts[i];++j){
                        cout<<(char)('a'+i);
                    }
                }
            }
            else{
                if(counts[first]*2<=str.size()+2){
                    cout<<(char)('a'+first)<<(char)('a'+first);
                    counts[first]-=2;
                    for(int i=0;i<26;++i){
                        if(i!=first){
                            for(int j=0;j<counts[i];++j){
                                cout<<(char)('a'+i);
                                if(counts[first]>0){
                                    cout<<(char)('a'+first);
                                    --counts[first];
                                }
                            }
                        }
                    }
                }
                else{
                    cout<<(char)('a'+first)<<(char)('a'+second);
                    --counts[first];
                    --counts[second];
                    int third=find_if_not(counts+second+1,counts+26,[](int x){return x==0;})-counts;
                    if(third!=26){
                        for(int i=0;i<counts[first];++i){
                            cout<<(char)('a'+first);
                        }
                        counts[first]=0;
                        cout<<(char)('a'+third);
                        --counts[third];
                        for(int i=0;i<26;++i){
                            for(int j=0;j<counts[i];++j){
                                cout<<(char)('a'+i);
                            }
                        }
                    }
                    else{
                        for(int i=0;i<counts[second];++i){
                            cout<<(char)('a'+second);
                        }
                        for(int i=0;i<counts[first];++i){
                            cout<<(char)('a'+first);
                        }
                    }
                }
            }
        }
        cout<<'\n';
        for(int i=0;i<26;++i)counts[i]=0;
    }
}