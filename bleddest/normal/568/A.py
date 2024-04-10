def palindromic(x):
    s = str(x)
    return s == s[::-1]

def main():
    p, q = map(int, input().split())
    n = 10 ** 7
    prime = [True for i in range(n + 1)]
    prime[0] = False
    prime[1] = False

    for i in range(2, n + 1):
        if prime[i]:
            for j in range(i ** 2, n + 1, i):
                prime[j] = False

    pi = 0
    rub = 0
    ans = 0
    for i in range(1, 10 ** 7):
        if prime[i]:
            pi += 1
        if palindromic(i):
            rub += 1
        if pi * q <= p * rub:
            ans = i
    if ans == 0:
        print('Palindromic tree is better than splay tree')
    else:
        print(ans)

main()