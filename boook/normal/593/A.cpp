#include<iostream>
using namespace std;
void check_sort(string word,int lonng[30][30])
{
    int word_long=word.size(),if_return=0,first=-1,second=-1;
    bool word_two[26]={};
    for(int afor=0;afor<word_long;afor++)
    {
        word_two[word[afor]-'a']=1;
    }
    for(int afor=0;afor<26;afor++)
        if(word_two[afor]==1)
        {
            if(first==-1)first=afor;
            else if(second==-1)second=afor;
            if_return++;
        }
//    cout<<"\t first="<<first<<" "<<second<<endl;
    if(if_return>2)
    {
//        cout<<"if_return=  "<<if_return<<endl;
        return ;
    }
    else if(if_return==2)
    {
        lonng[first][second]+=word_long;
    }
    else
    {
        for(int afor=0;afor<26;afor++)
        {
            if(first!=afor)
            {
                lonng[first][afor]+=word_long;
                lonng[afor][first]+=word_long;
            }
        }
    }
    return ;
}
void clean(int lonng[30][30])
{
    for(int afor=0;afor<30;afor++)
        for(int bfor=0;bfor<30;bfor++)
            lonng[afor][bfor]=0;
}
int main()
{
    cout.sync_with_stdio(false);
    int howmany,lonng[30][30];
    while(cin>>howmany)
    {
        clean(lonng);
        string word;
        for(int afor=0;afor<howmany;afor++)
        {
            cin>>word;
            check_sort(word,lonng);
        }
        int answer=0;
        for(int afor=0;afor<30;afor++)
            for(int bfor=0;bfor<30;bfor++)
            {
                if(afor==bfor)continue;
                if(answer<lonng[afor][bfor])answer=lonng[afor][bfor];
            }
        cout<<answer<<endl;
    }
    return 0;
}