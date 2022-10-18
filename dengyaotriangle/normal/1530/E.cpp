#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

int ocr[26];
int tmp[26];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        memset(ocr,0,sizeof(ocr));
        for(char u:s)ocr[u-'a']++;
        int cn0=count_if(ocr,ocr+26,[](int x){return !!x;});
        if(cn0==1){
            cout<<s<<'\n';
        }else{
            int id=-1;
            for(int i=0;i<26;i++)if(ocr[i]==1){
                id=i;break;
            }
            if(id==-1){
                int px;
                for(int i=0;i<26;i++)if(ocr[i]){
                    px=i;break;
                }
                memcpy(tmp,ocr,sizeof(ocr));
                string ret;
                ret+=char('a'+px);
                ret+=char('a'+px);
                int rp=px+1;bool lp=1;
                bool suc=1;
                ocr[px]-=2;
                for(int i=2;i<(int)s.size();i++){
                    if(!ocr[px]||lp){
                        while(rp<26&&!ocr[rp])rp++;
                        if(rp==26){
                            suc=0;
                            break;
                        }
                        ret+=char('a'+rp);ocr[rp]--;
                        lp=0;
                    }else{
                        ret+=char('a'+px);
                        ocr[px]--;
                        lp=1;
                    }
                }
                if(suc){
                    cout<<ret<<'\n';
                }else{
                    memcpy(ocr,tmp,sizeof(ocr));
                    if(cn0==2){
                        cout<<char('a'+px);
                        for(int i=0;i<26;i++)if(i!=px){
                            for(int j=0;j<ocr[i];j++)cout<<char('a'+i);
                        }
                        for(int j=1;j<ocr[px];j++)cout<<char('a'+px);
                        cout<<'\n';
                    }else{
                        int spx;
                        for(int i=0;i<26;i++)if(i!=px&&ocr[i]){spx=i;break;}
                        int tpx;
                        for(int i=0;i<26;i++)if(i!=px&&i!=spx&&ocr[i]){tpx=i;break;}
                        cout<<char('a'+px)<<char('a'+spx);
                        for(int i=1;i<ocr[px];i++)cout<<char('a'+px);
                        cout<<char('a'+tpx);
                        for(int i=1;i<ocr[spx];i++)cout<<char('a'+spx);
                        for(int i=1;i<ocr[tpx];i++)cout<<char('a'+tpx);
                        for(int i=tpx+1;i<26;i++)for(int j=0;j<ocr[i];j++)cout<<char('a'+i);
                        cout<<'\n';
                    }
                }
            }else{
                cout<<char(id+'a');
                for(int i=0;i<26;i++)if(i!=id){
                    for(int j=0;j<ocr[i];j++)cout<<char('a'+i);
                }
                cout<<'\n';
            }
        }
    }
    return 0;
}