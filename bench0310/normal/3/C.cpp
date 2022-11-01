#include <iostream>

using namespace std;

int main()
{
    string ln;
    int arr[3][3];
    int crosses=0,noughts=0;
    for(int o=0;o<3;o++)
    {
        cin >> ln;
        for(int i=0;i<3;i++)
        {
            switch(ln[i])
            {
                case 'X': arr[o][i]=1;
                          crosses++;
                          break;
                case '0': arr[o][i]=2;
                          noughts++;
                          break;
                case '.': arr[o][i]=0;
                          break;
            }
        }
    }
    //Check number
    if(crosses>noughts+1||crosses<noughts)
    {
        cout << "illegal" << endl;
        return 0;
    }
    //Check winner
    int wins=0;
    bool winner[2]={0,0};
    for(int o=0;o<3;o++)
    {
        if((arr[o][0]==arr[o][1])&&(arr[o][1]==arr[o][2]))
        {
            if(arr[o][0])
            {
                wins++;
                winner[arr[o][0]-1]=1;
            }
        }
    }
    for(int o=0;o<3;o++)
    {

        if((arr[0][o]==arr[1][o])&&(arr[1][o]==arr[2][o]))
        {
            if(arr[0][o])
            {
                wins++;
                winner[arr[0][o]-1]=1;
            }
        }
    }
    if((arr[0][0]==arr[1][1])&&(arr[1][1]==arr[2][2]))
    {
        if(arr[0][0])
        {
            wins++;
            winner[arr[0][0]-1]=1;
        }
    }
    if((arr[0][2]==arr[1][1])&&(arr[1][1]==arr[2][0]))
    {
        if(arr[0][2])
        {
            wins++;
            winner[arr[0][2]-1]=1;
        }
    }
    if(winner[0]&&winner[1])
    {
        cout << "illegal" << endl;
        return 0;
    }
    if(winner[0])
    {
        if(crosses==noughts)
        {
            cout << "illegal" << endl;
            return 0;
        }
        cout << "the first player won" << endl;
        return 0;
    }
    if(winner[1])
    {
        if(crosses==noughts+1)
        {
            cout << "illegal" << endl;
            return 0;
        }
        cout << "the second player won" << endl;
        return 0;
    }
    if(crosses+noughts==9)
    {
        cout << "draw" << endl;
        return 0;
    }
    if(crosses==noughts)
    {
        cout << "first" << endl;
        return 0;
    }
    if(crosses==noughts+1)
    {
        cout << "second" << endl;
        return 0;
    }
    return 0;
}