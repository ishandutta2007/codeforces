/*
 * @Author: BilyHurington
 * @Date: 2020-02-13 22:32:46
 * @LastEditors  : BilyHurington
 * @LastEditTime : 2020-02-13 23:52:30
 */
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<set>
#include<map>
#include<vector>
#include<queue>
using namespace std;
int n,m,k;
vector<pair<int,string> > ans;
bool add(int ti,string s){
    if(ti*s.length()<k){
        k-=ti*s.length();
        ans.push_back(make_pair(ti,s));
        return 1;
    }
    int x=k/s.length();
    k-=x*s.length();
    ans.push_back(make_pair(x,s));
    if(!k) return 0;
    string sw;
    for(int i=0;i<k;i++) sw=sw+s[i];
    ans.push_back(make_pair(1,sw));
    return 0;
}
int main(){
    scanf("%d %d %d",&n,&m,&k);
    bool pd=1;
    for(int i=1;i<n;i++){
        if(!add(m-1,"R")){
            pd=0;
            break;
        }
        if(!add(m-1,"DUL")){
            pd=0;
            break;
        }
        if(!add(1,"D")){
            pd=0;
            break;
        }
    }
    if(!pd){
        printf("YES\n");
        int cnt=0;
        for(int i=0;i<ans.size();i++){
        	if(ans[i].first) cnt++;
		}
		printf("%d\n",cnt);
        for(int i=0;i<ans.size();i++){
        	if(!ans[i].first) continue;
			printf("%d ",ans[i].first);
			cout<<ans[i].second<<endl;
		} 
        return 0;
    }
    if(!add(m-1,"R")){
        printf("YES\n");
        int cnt=0;
        for(int i=0;i<ans.size();i++){
        	if(ans[i].first) cnt++;
		}
		printf("%d\n",cnt);
        for(int i=0;i<ans.size();i++){
        	if(!ans[i].first) continue;
			printf("%d ",ans[i].first);
			cout<<ans[i].second<<endl;
		} 
        return 0;
    }
    if(!add(m-1,"L")){
        printf("YES\n");
        int cnt=0;
        for(int i=0;i<ans.size();i++){
        	if(ans[i].first) cnt++;
		}
		printf("%d\n",cnt);
        for(int i=0;i<ans.size();i++){
        	if(!ans[i].first) continue;
			printf("%d ",ans[i].first);
			cout<<ans[i].second<<endl;
		} 
        return 0;
    }
    if(!add(n-1,"U")){
        printf("YES\n");
        int cnt=0;
        for(int i=0;i<ans.size();i++){
        	if(ans[i].first) cnt++;
		}
		printf("%d\n",cnt);
        for(int i=0;i<ans.size();i++){
        	if(!ans[i].first) continue;
			printf("%d ",ans[i].first);
			cout<<ans[i].second<<endl;
		} 
        return 0;
    }
    printf("NO\n");
    return 0;
}