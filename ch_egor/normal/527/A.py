def main():
    a, b = map(int, input().split())

    answer = 0
    
    while (a>0 and b>0):
        if (a>b):
            a, b = b, a

        answer += b//a
        b %= a

    print(answer)
        

main()