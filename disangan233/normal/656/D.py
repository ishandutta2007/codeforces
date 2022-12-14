#!/usr/bin/python3
a=int(input())
b=0
while a:
    if a%8==1: b=b+1
    a//=8
print(b)