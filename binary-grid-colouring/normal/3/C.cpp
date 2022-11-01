#include<bits/stdc++.h>
using namespace std;
char s[4][4];
bool win(char x)
{
    for (int i=0;i<3;i++)
    {
        if (s[i][0]==s[i][1]&&s[i][0]==s[i][2]&&s[i][0]==x) 
		return true;
        if (s[0][i]==s[1][i]&&s[0][i]==s[2][i]&&s[0][i]==x) 
		return true;
        if (s[0][0]==s[1][1]&&s[0][0]==s[2][2]&&s[0][0]==x) 
		return true;
        if (s[0][2]==s[1][1]&&s[0][2]==s[2][0]&&s[0][2]==x) 
		return true;
    }
    return false;
}
int main()
{
    for (int i=0;i<3;i++)
        scanf("%s",s[i]);
        
    int cnt1=0,cnt2=0;
    for (int i=0;i<3;i++){
    	for (int j=0;j<3;j++){
    		if (s[i][j]=='X') cnt1++;
            else if (s[i][j]=='0') cnt2++;
		}
            
	}
        
    if (cnt1!=cnt2 && cnt1!=cnt2+1) puts("illegal");
    
    else if (win('X')&&win('0')) puts("illegal");
    
    else if (win('X')&&cnt1==cnt2) puts("illegal");
    
    else if (win('0')&&cnt1==cnt2+1) puts("illegal");
    
    else if (win('X')) puts("the first player won");
    
    else if (win('0')) puts("the second player won");
    
    else if (cnt1+cnt2==9) puts("draw");
    
    else if (cnt1==cnt2) puts("first");
    
    else puts("second");
    return 0;
}