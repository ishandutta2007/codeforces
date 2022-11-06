t = int(input())

while t > 0:
    t = t - 1
    n = int(input())
    arr = list(map(int, input().split()))

    a = 0
    b = len(arr) - 1

    moves = 0

    alice = 0
    bob = 0

    last_a = 0
    last_b = 0

    while a <= b:
        moves = moves + 1

        last_a = 0
        while last_a <= last_b and a <= b:
            last_a = last_a + arr[a]
            a = a + 1

        alice = alice + last_a
        
        if a > b: 
            break

        moves = moves + 1

        last_b = 0
        while last_b <= last_a and a <= b:
            last_b = last_b + arr[b]
            b = b - 1

        bob = bob + last_b
        if a > b:
            break
    
    print(moves, alice, bob)