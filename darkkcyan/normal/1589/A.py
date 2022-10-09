print("\n".join(
    (lambda u, v: f"{u * u} {-v * v}")(*map(int, input().split()))
    for _ in range(int(input()))))