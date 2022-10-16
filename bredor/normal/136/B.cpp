//  228

#include <bits/stdc++.h>
#include <iostream>
#include <string.h>
#include <cmath>
#include <algorithm>
#include <fstream>
#include <cstdio>
using namespace std;
#define ll long long int

void charswap(char* a, char* b)
{
    char t = *a;
    *a = *b;
    *b = t;
}

void charbubble(char array[], int n)
{
    int i, j;
    bool swapped;
    for(i = 0; i < n-1; i++)
    {
        swapped = false;
        for(j = 0; j < n-i-1; j++)
        {
            if(array[j] > array[j+1])
            {
                charswap(&array[j], &array[j+1]);
                swapped = true;
            }
        }
        if(swapped == false)
            break;
    }
}

void intswap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void intbubble(int array[], int n)
{
    int i, j;
    bool swapped;
    for(i = 0; i < n-1; i++)
    {
        swapped = false;
        for(j = 0; j < n-i-1; j++)
        {
            if(array[j] > array[j+1])
            {
                intswap(&array[j], &array[j+1]);
                swapped = true;
            }
        }
        if(swapped == false)
            break;
    }
}

void longswap(long long* a, long long* b)
{
    long long t = *a;
    *a = *b;
    *b = t;
}

void longbubble(long long array[], long long n)
{
    long long i, j;
    bool swapped;
    for(i = 0; i < n-1; i++)
    {
        swapped = false;
        for(j = 0; j < n-i-1; j++)
        {
            if(array[j] > array[j+1])
            {
                longswap(&array[j], &array[j+1]);
                swapped = true;
            }
        }
        if(swapped = false)
            break;
    }
}

void lowercase(char array[], int n)
{
    for(int i = 0; i < n; i++)
    {
        if(array[i] < 97)
            array[i] = array[i] + 32;
    }
}
 
int intsmallest(int a, int b, int c)
{
    return (a<b ? (a<c?a:c) : (b<c?b:c));
}

int intgreatest(int a, int b, int c)
{
    return (a>b ? (a>c ? a : c) : (b>c ? b : c));
}

int factorial(int n)
{
    if( n == 0)
        return 1;
    else
        return n* factorial(n-1);
}

long long fact(long long n)
{
    if(n == 0)
        return 1;
    else
        return n * fact(n-1);
}

void strshiftleft(char array[], int index, int length)
{
    int j;
    j = index;
    while(j < length)
    {
        if(array[j+1] != '-')
        {
            array[j] = array[j+1];
            
        }
        j++;
    }
}

long long fun(long long n)
{
    {
        int i;
        for(i = 3; i <= n; i++)
        {
            if(n % i == 0)
                break;
            else
                i++;
                
        }
        return i;
    }
    
}

long long larger(long long a, long long b)
{
    return (a>b ? a : b);
}

long long smallerlong(long long a, long long b)
{
    return (a < b? a : b);
}

int smallerint(int a, int b)
{
    return (a < b ? a : b);
}

int largerint(int a, int b)
{
    return (a > b ? a : b);
}

long long maxfreq(long long array[], long long n)
{
    long long maxcount = 0;
    long long max;
    long long i = 0;
    while(i < n-1)
    {
        long long count = 1;
        
        bool flag = true;
        //int j = i;
        while(flag == true)
        {
            if(array[i] == array[i+1])
            {
                count++;
                flag = true;
            }
            else
            {
                flag = false;
            }
            i++;
        }
        //cout<< count<<endl;
        if(count > maxcount)
        {
            maxcount = count;
            max = array[i-1];
            //cout<< max <<endl;
            
        }
        //i = i + count;
    }
    return max;
}

int intpartition(int array[], int low, int high)
{
    int pivot = array[high];
    int i = low - 1;
    
    for(int j = low; j <= high-1; j++)
    {
        if(array[j] < pivot)
        {
            i++;
            intswap(&array[i], &array[j]);
        }
    }
    intswap(&array[i+1], &array[high]);
    return i+1;
}

void intquick(int array[], int low, int high)
{
    if(low < high)
    {
        int pi = intpartition(array, low, high);
        intquick(array, low, pi-1);
        intquick(array, pi+1, high);
    }
}

long long longpartition(long long array[], long long low, long long high)
{
    long long pivot = array[high];
    long long i = low - 1;
    
    for(long long j = low; j <= high-1; j++)
    {
        if(array[j] < pivot)
        {
            i++;
            longswap(&array[i], &array[j]);
        }
    }
    longswap(&array[i+1], &array[high]);
    return i+1;
}

void longquick(long long array[], long long low, long long high)
{
    if(low < high)
    {
        long long pi = longpartition(array, low, high);
        longquick(array, low, pi-1);
        longquick(array, pi+1, high);
    }
}

long long longgreatest(long long a, long long b, long long c)
{
    return (a>b ? (a>c ? a : c) : (b>c ? b : c));
}

bool primecheck(long long n)
{
    bool flag = false;
    if(n == 2)
        return true;
    else if(n % 2 == 0)
        return false;
    else
    {
        for(long long i = 3; i <= n/2; i=i+2)
        {
            if(n % i == 0)
            {
                flag = true;
                break;
            }
        }
        if(flag == true)
            return false;
        else
            return true;
    }
    
}

int lcm(int a, int b, int c)
{
    int d = intgreatest(a, b, c);
    int j = d;
    while(j <= a*b*c)
    {
        if(j % a == 0 && j%b == 0 && j%c == 0)
            break;
        else
            j = j + d;
    }
    return j;
}


int main()
{
    ll a, c, b, d;
    cin >> a >> c;
    b = a;
    d = c;
    ll count1 = 0, count2 = 0, i = 0, j = 0;
    while(b > 0)
    {
        b = b/3;
        count1++;
    }
    while(d > 0)
    {
        d = d/3;
        count2++;
    }
    
    int count = largerint(count1, count2);
    int array1[count], array2[count], array3[count];
    for(int e = 0; e < count; e++)
    {
        array1[e] = 0;
        array2[e] = 0;
        array3[e] = 0;
    }
    // for(int e = 0; e < count; e++)
    // {
    //     cout << array1[e]<< " ";
    // }
    // cout<< endl;
    
    while(a > 0)
    {
        // int d = a % 3;
        array1[count-1-i] = a % 3;
        a = a/3;
        i++;
    }
    while(c > 0)
    {
        // int d = c % 3;
        array2[count-1-j] = c % 3;
        c = c/3;
        j++;
    }
    for(int l = 0; l < count; l++)
    {
        if(array1[l] == 0)
        {
            if(array2[l] == 0)
                array3[l] = 0;
            else if(array2[l] == 1)
                array3[l] = 1;
            else
                array3[l] = 2;
        }
        else if(array1[l] == 1)
        {
            if(array2[l] == 1)
                array3[l] = 0;
            else if(array2[l] == 2)
                array3[l] = 1;
            else
                array3[l] = 2;
        }
        else
        {
            if(array2[l] == 2)
                array3[l] = 0;
            else if(array2[l] == 0)  
                array3[l] = 1;
            else
                array3[l] = 2;
        }
    }
    ll number = 0;
    // for(int k = 0; k < count; k++)
    // {
    //     cout << array1[k] << " ";
    // }
    // cout<<endl;
    // for(int k = 0; k < count; k++)
    // {
    //     cout << array2[k] << " ";
    // }
    // cout << endl;
    for(int k = 0; k < count; k++)
    {
        // cout << array3[k] << " ";
        
        number = number + (pow(3, k) * array3[count-k-1]);
    }
    
    cout <<endl<< number;
    
    
    
    
    
    
    
    
    return 0;
}