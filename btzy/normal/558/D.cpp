#include<cstdio>
#include<map>
#include<algorithm>
using namespace std;
int h,q,l,ans;
long long L,R;
map<long long,bool>mp;
// true:becoming yes
int main(){
    scanf("%d%d",&h,&q);
    mp.insert(mp.end(),make_pair(0ll,true));
    mp.insert(mp.end(),make_pair(1ll<<(h-1),false));
    for(int i=0;i<q;++i){
        scanf("%d%I64d%I64d%d",&l,&L,&R,&ans);
        L-=1ll<<(l-1);
        L=max(L,0ll);
        L<<=(h-l);
        R-=1ll<<(l-1);
        ++R;
        R=min(R,1ll<<(l-1));
        R<<=(h-l);
        //printf("%lld %lld --\n",L,R);
        if(ans==1){
            mp.erase(mp.begin(),mp.upper_bound(L));
            if(mp.size()%2)mp.insert(mp.begin(),make_pair(L,true));
            mp.erase(mp.lower_bound(R),mp.end());
            if(mp.size()%2)mp.insert(mp.end(),make_pair(R,false));
        }
        else{
            map<long long,bool>::iterator lit=mp.lower_bound(L);
            map<long long,bool>::iterator rit=mp.upper_bound(R);
            bool lst=((lit!=mp.end())?(!(lit->second)):false),rst=((rit!=mp.end())?(!(rit->second)):false);
            mp.erase(lit,rit);
            if(lst)mp.insert(rit,make_pair(L,false));
            if(rst)mp.insert(rit,make_pair(R,true));
        }
        /*for(map<long long,bool>::iterator it=mp.begin();it!=mp.end();++it){
            printf("%lld %d m\n",it->first,it->second);
        }*/
    }
    if(mp.size()==2&&mp.begin()->first+1>=(++(mp.begin()))->first)printf("%I64d\n",(1ll<<(h-1))+mp.begin()->first);
    else if(mp.size()<2)printf("Game cheated!\n");
    else printf("Data not sufficient!\n");
}